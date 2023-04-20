#!/usr/bin/perl


my @sources = @ARGV;
my %includes;
my @sysincludes = ();
my @incs = [];
my $res = "";

my %defines;
$defines{'0'} = 0;
$defines{'1'} = 1;

my @ifdepth;

sub sum {
    my @arg = @_;

    my $sum = 0;
    foreach my $val (@arg){
        $sum += $val;
    }
    return $sum;
}




sub parse_file {
    my $source = shift;
    open my $fh, '<', $source or die "Failed to open $source: $!";

    while (my $line = <$fh>) {


        $line =~ s/(\s\/\/.*)//;


        if($line =~ /^#ifdef\s(.*)$/){
            my $def = $1;
            if(!$defines{$def}){
                push(@ifdef,1);
            }
            else{
                push(@ifdef,0);
            }
            next;

        }

        if($line =~ /^#ifndef\s(.*)$/){
            my $def = $1;
            if($defines{$def}){
                push(@ifdef,1)
            }
            else{
                push(@ifdef,0);
            }
            next;
        }

        if($line =~ /^#endif(.*)$/){
            pop(@ifdef);
            next;
        }


        if($line =~ /^#if\s(.*)$/){

            my $to_eval = $1;
            if($1 =~ /defined/){
                $to_eval =~  s/defined\(([^\s]+)\)/defined \$defines{\'$1\'}/g;
            }
            else{
                $to_eval =~ s/([A-Za-z0-9\_]+$)/\$defines{\'$1\'}/g;
            }

            if(!eval($to_eval)){
                push(@ifdef,1);
                next;
            }
            else{
                push(@ifdef,0);
                next;
            }
        }


        if($line =~ /^#else.*/ && sum(@ifdef)==1){
            $ifdef[@ifdef-1] = 0;
            next;
        }
        if($line =~ /^#else.*/ && sum(@ifdef)==0){
            $ifdef[@ifdef-1] = 1;
            next;
        }


        if(sum(@ifdef)>0){
            next;
        }

        #line respecting here
        if($line =~ /^#define\s+([^\s]+)\s(.*)$/){
            my $def = $1;
            my $val = $2 || 1;
            
            $defines{$def} = $val;
            $res .= $line;
            next;
        }

        if ($line =~ /^(\s*#include[\t\s]+.*)/) {
            my $include = $1;
            unless ($includes{$include}) {
                $includes{$include} = 1;
                if ($include =~ /^#include[\t\s]+"(.*)"/) {
                    parse_file("client/".$1);
                }
                else{
                    push(@sysincludes, $line);
                }
            }
            next;
        }
        
        $res .= $line;    
        
    }
    
    close $fh;
}


foreach my $source (@sources) {
    parse_file($source);
}



foreach my $inc (@sysincludes) {
  print "$inc";
}

print $res;