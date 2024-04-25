# Simple Port Scanner

This C++ program is a simple port scanner designed for personal research and educational purposes. It allows users to scan either a local machine or a remote host for open or closed ports. 

**Disclaimer:** 
- This project was developed for personal research and education purposes only.
- Do not use this tool to scan networks or ports that you do not have permission to scan.

### Project Details:

- **Date Created:** 14 Jun 2022
- **Author:** Kyle Noel

### Features:

- **Local or Remote Scan:** Users can choose between scanning the localhost or entering a specific IP address for remote scanning.
- **Single Port Scan:** Enables scanning of a single specified port to check its status (open or closed) on the target host.
- **Range Port Scan:** Supports scanning a range of ports to check the status of multiple ports on the target host.
- **Port Status Detection:** Utilizes SFML's networking module to attempt a connection to each port and determine whether it is open or closed.
- **Restart Option:** Provides the option to perform another scan after completing each scan session.

### Usage:

1. **Local or Remote Scan:**
   - Choose option 1 to scan the localhost.
   - Choose option 2 to enter a specific IPv4 address or a valid URL for remote scanning.

2. **Single Port Scan or Range Port Scan:**
   - For a single port scan, select option 1 and input the port number to scan.
   - For a range scan, select option 2 and input the starting and ending port numbers to scan within that range.

3. **Scan Results:**
   - After selecting the scan type and providing necessary inputs, the program displays the results indicating the status of each scanned port (open or closed).

4. **Restart or Terminate:**
   - After completing each scan session, the program prompts the user to choose whether to perform another scan (Y/N).
   - Entering 'Y' or 'y' will restart the program for another scan session.
   - Entering 'N' or 'n' will terminate the program.

### Security Note:

- Ensure that you have proper authorization before scanning any network or port. Unauthorized scanning may violate laws and regulations.

### Compatibility:

- The program is designed for C++ environments and may require adjustments for specific operating systems or environments.
- Currently, it includes directives for clearing the console for Windows systems. Adjustments may be needed for other platforms.
