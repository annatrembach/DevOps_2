#include <iostream>
#include <curl/curl.h>
#include <ctime>
#include <cassert>

class TestServerResponseTime {
public:
    void test_response_time() {
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            std::string response_body;

            curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8081/trigvalues");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_body);

            clock_t start_time = clock();
            res = curl_easy_perform(curl);
            clock_t end_time = clock();

            if (res != CURLE_OK) {
                std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
            } else {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

                assert(response_code == 200 && "Incorrect status code");

                try {
                    int server_response_time = std::stoi(response_body);
                    std::cout << "Server Response Time: " << server_response_time << " ms" << std::endl;

                    if (server_response_time >= 5000 && server_response_time <= 20000) {
                        std::cout << "Test Passed!" << std::endl;
                    } else {
                        std::cout << "Test Failed! Response time out of range." << std::endl;
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Failed to parse response: " << e.what() << std::endl;
                }
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();
    }

private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
};

int main() {
    TestServerResponseTime test;
    test.test_response_time();
    return 0;
}

