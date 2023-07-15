# IP_RaW
Network man-in-the-middle attack tools for Education 
_______________________________________________________________________________________________________________________________


To run the modified code:

1. Open a text editor and paste the updated code.
2. Save the file with a `.c` extension, for example, `IP_Raw.c`.
3. Open a terminal and navigate to the directory where you saved the `IP_Raw.c` file.
4. Compile the C code using the following command:
   ```
   gcc -o mitm IP_Raw.c -lpcap
   ```
5. After successful compilation, you can run the compiled binary and provide the target IP address as a command-line argument. For example:
   ```
   ./mitm 192.168.1.100
   ```
   Replace `192.168.1.100` with the actual IP address of the target machine.

The program will start sniffing network traffic on the specified interface (`eth0`) and perform the actions defined in the `process_packet` function.
