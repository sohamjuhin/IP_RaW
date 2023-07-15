#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void process_packet(const u_char *packet, int length) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Assuming Ethernet header size is 14 bytes
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + 14 + ip_header->ip_hl * 4);

    // Modify the packet as needed (e.g., change payload, IP addresses, etc.)
    // Note: Modifying packets at this level requires a deep understanding of network protocols

    // Forward the modified packet to the intended recipient
    // Note: Implementing packet sending functionality in C is beyond the scope of this example
}

void start_mitm_attack(const char *target_ip) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf); // Replace "eth0" with the appropriate interface name

    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        return;
    }

    // Set up packet sniffing and interception
    while (1) {
        packet = pcap_next(handle, &header);
        process_packet(packet, header.len);
    }

    pcap_close(handle);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    const char *target_ip = argv[1];
    start_mitm_attack(target_ip);
    return 0;
}
