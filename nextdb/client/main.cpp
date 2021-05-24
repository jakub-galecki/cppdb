#include "include/httplib.h"
#include "include/jsonrpcpp.hpp"
#include "include/json.hpp"
#include "iostream"

using json = nlohmann::json;

int main(){
    httplib::Server server;
    server.Post("/db", [](const httplib::Request &req, httplib::Response &res) {
        jsonrpcpp::entity_ptr msg = jsonrpcpp::Parser::do_parse(req.body);
        if(msg->is_request()){
            jsonrpcpp::request_ptr request = std::dynamic_pointer_cast<jsonrpcpp::Request>(msg);
            if (request->method() == "insert"){
                int key = request->params().get("key");
                std::string value = request->params().get("value");

                json j {{"key", key}, {"value", value}}; // TODO: Put here response from the server
                jsonrpcpp::Response response(*request, j);
                res.set_content(response.to_json().dump(), "application/json");
            }
        }
    });
    server.listen("localhost",8080);
}

