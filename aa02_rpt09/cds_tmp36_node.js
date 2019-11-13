// cds_tmp36_node.js

var serialport = require('serialport');
var portName = 'COM';  // check your COM port!!
var port    =   process.env.PORT || 3000;

var io = require('socket.io').listen(port);

// serial port object
var sp = new serialport(portName,{
    baudRate: 9600,   // 9600  38400
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline('\r\n')  // new serialport.parsers.Readline
});

var readData = '';  // this stores the buffer/
var temp ='';
var lux ='';
var mdata =[]; // this array stores date and data from multiple sensors
var firstcommaidx = 0; /컴마값을 찾기위함/

sp.on('data', function (data) { // call back when data is received
    readData = data.toString(); // append data to buffer
    firstcommaidx = readData.indexOf(','); 
    //console.log(data);

    // parsing data into signals
    if (firstcommaidx > 0) { /컴마 인덱스가 영보다 크면/
        temp = readData.substring(0, firstcommaidx);
        lux = readData.substring(firstcommaidx + 1);     
        readData = '';
        
        dStr = getDateString();
        mdata[0]= dStr;  // Date
        mdata[1]=temp;  // temperature data
        mdata[2]=lux;   // luminosity data
        console.log("AA02," + mdata );
        io.sockets.emit('message', mdata);  // send data to all clients 

    } else {  // error 
        console.log(readData);
    }
    
});


io.sockets.on('connection', function (socket) {
    // If socket.io receives message from the client browser then 
    // this call back will be executed.
    socket.on('message', function (msg) {
        console.log(msg);
    });
    // If a web browser disconnects from Socket.IO then this callback is called.
    socket.on('disconnect', function () {
        console.log('disconnected');
    });
});

// helper function to get a nicely formatted date string
function getDateString() {
    var time = new Date().getTime();
    // 32400000 is (GMT+9 Korea, GimHae)
    // for your timezone just multiply +/-GMT by 3600000
    var datestr = new Date(time +32400000).
    toISOString().replace(/T/, ' ').replace(/Z/, '');
    return datestr;
}