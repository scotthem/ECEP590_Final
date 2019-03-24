#include <iostream>
#include <fstream>
#include <ctime>

#include "httplib/httplib.h"
#include "json/json.h"

int main(void) {
    using namespace httplib;
    using nlohmann::json; 

    Server svr;

    int next_id = 0;

    svr.Post("/save", [&](const Request& req, Response& res) {
        json request, result;

        try {
            request = json::parse(req.body);
        } catch(json::exception e) {
            result["result"] = "error";
            result["message"] = e.what();
            res.set_content(result.dump(), "json");
            return;
        }

        std::cout << "Got new save request " << request.dump() << std::endl;  

        std::fstream fs;
        time_t t = std::time(0);
        long int now = static_cast<long int> (t);

        fs.open ("log.txt", std::ios_base::app);
        
        if (fs.is_open()) {
            fs << now << " " << request.dump() << std::endl;
            fs.close();
        } else {
            throw std::runtime_error("Cannot open file for writing");
        }

        result["result"] = "ok";
        result["id"] = next_id++;
        res.set_content(result.dump(), "json");

    });

    svr.listen("0.0.0.0", 80); // Note, only this port is exposed to 
                                 // host machine

    std::cout << "You can't see me, because svr.listen never returns\n";
}