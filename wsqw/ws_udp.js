var WebSocket = require('ws'); 
var udp = require('dgram');
const querystring = require('querystring');



var wss = new WebSocket.WebSocketServer({port: 5555});
wss.on('connection', function connection(qw_player,req) {
	console.log(req.url);

	if(!req.url){
		return;
	}
	let params = querystring.parse(req.url);
	console.log(params)

	var qw_server = udp.createSocket('udp4');
	qw_server.on('message',function(msg,info){
		console.log('Data received from server : ' + msg.toString());
		console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);
		qw_player.send(msg);
	});



	qw_player.on('message', function message(data) {
		let host_info = data.toString().split("xDDxxDDx")[0];
		let host = host_info.split(':')[0];
		let port = Number.parseInt(host_info.split(':')[1]);
		//console.log(host_info,host_info.length);
		//console.log(data);
		//console.log(host, port, data.toString(),data.slice(host_info.length+1+8),"???");
		let to_send = data.slice(host_info.length+1+8);
		console.log(to_send,to_send.toString(),host,port);
		try{
			qw_server.send(to_send,port,host);
		}
		catch{
			console.log("whops")
		}

	});


});