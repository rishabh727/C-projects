#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// List to store open ports
std::vector<int> open_ports;

void print_progress_bar(int current, int total);

void handle_connect(const boost::system::error_code& error, boost::asio::ip::tcp::socket& socket, int target_port, int& total_ports, int& scanned_ports) {
    if (!error) {
        // Connection successful
        open_ports.push_back(target_port);
        std::cout << "[+] Port " << target_port << "/tcp is open                                    " << std::endl;
    }
    // Update the scanned ports counter
    ++scanned_ports;
    // Print the progress bar
    print_progress_bar(scanned_ports, total_ports);
    // No need to close the socket here, as it will be closed automatically when it goes out of scope
}

// Define the print_progress_bar function after it's declared
void print_progress_bar(int current, int total) {
    int bar_width = 50;
    double progress = static_cast<double>(current) / total;
    int pos = static_cast<int>(bar_width * progress);

    std::cout << "[";
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << std::fixed << std::setprecision(2) << (progress * 100.0) << " %\r";
    std::cout.flush();
}

void scan_port(const std::string& target_host, int target_port, int& total_ports, int& scanned_ports) {
    try {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket(io_service);
        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query(target_host, std::to_string(target_port));
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        // Set a timeout for the connection attempt
        boost::asio::deadline_timer timer(io_service);
        timer.expires_from_now(boost::posix_time::millisec(100));
        timer.async_wait([&socket](const boost::system::error_code& error) {
            if (!error) {
                socket.close();
            }
        });

        // Attempt to connect to the target host and port
        boost::asio::async_connect(socket, endpoint_iterator, [&socket, target_port, &total_ports, &scanned_ports](const boost::system::error_code& error, boost::asio::ip::tcp::resolver::iterator) {
            handle_connect(error, socket, target_port, total_ports, scanned_ports);
        });

        // Run the io_service to perform the asynchronous operations
        io_service.run();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    // Specify the target host and port range
    std::string target_host;
    int start_port, end_port;

    std::cout << "Enter the target host: ";
    std::cin >> target_host;
    std::cout << "Enter the start port: ";
    std::cin >> start_port;
    std::cout << "Enter the end port: ";
    std::cin >> end_port;

    int total_ports = end_port - start_port + 1;
    int scanned_ports = 0;

    // Call the port_scanner function
    for (int port = start_port; port <= end_port; ++port) {
        scan_port(target_host, port, total_ports, scanned_ports);
    }

    // Print the list of open ports
    std::cout << "\nOpen ports:" << std::endl;
    for (int port : open_ports) {
        std::cout << port << std::endl;
    }

    return 0;
}
