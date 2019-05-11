#include "cpp-httplib/httplib.h"    
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

const std::string load_assets(const std::string& path) {

    std::ifstream file(path.c_str(), std::ios::in);

    std::stringstream stream;

    stream << file.rdbuf();

    file.close();

    std::string assets(stream.str());

    return assets;
}


int main() {

    httplib::Server svr;

    std::string body = load_assets("index.html");

    std::string indexjs = load_assets("src.js");

    svr.Get("/src.js", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(indexjs, "text/javascript");
    });

    svr.Get("/", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(body, "text/html");
    });

    svr.Post("/post", [](const httplib::Request& req, httplib::Response& res){
        std::cout << req.params.count("params") << std::endl;

        res.set_content("hoge", "text/plain");
    });

    svr.listen("localhost", 3000);

}