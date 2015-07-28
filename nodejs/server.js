/*jshint node: true*/
var http = require("http");
var fs = require("fs");

var mainPage = fs.readFileSync(__dirname + "/index.html");

// Expand this section to handle dynamic content
var slides = fs.readdirSync(__dirname + "/slides");
var slideIndex = 0;
//But for now just give a static listing generated at server startup
function sendSlide(req, res) {
    var path = __dirname + "/slides/" + slides[slideIndex];
    console.log(path);
    fs.createReadStream(path).pipe(res);
    slideIndex++;
    if (slideIndex >= slides.length)
        slideIndex = 0;
}

http.createServer(function (req, res) {
    if (req.url === "/") {
        //Send main page
        res.writeHead(200);
        res.end(fs.readFileSync(__dirname + "/index.html"));
    } else {
        var get = req.url.match(/^\/get.*$/mgi);
        if (get) {
            // Note: no protection against empty directories
            if (slides[slideIndex]) {
                res.writeHead(200);
                sendSlide(req, res);
            } else {
                res.writeHead(404);
                res.end();
            }
        } else {
            res.writeHead(404);
            res.end();
        }
    }

}).listen(81);
