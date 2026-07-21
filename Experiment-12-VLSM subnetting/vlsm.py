import ipaddress

network = input("Enter Network (e.g. 192.168.10.0/24): ")

n = int(input("Enter Number of Departments: "))

hosts = []

for i in range(n):
    h = int(input(f"Hosts required for Department {i+1}: "))
    hosts.append(h)

hosts.sort(reverse=True)

current_network = ipaddress.ip_network(network, strict=False)

current_ip = int(current_network.network_address)

print("\nVLSM Allocation\n")

for h in hosts:

    needed = h + 2

    bits = 0

    while (2 ** bits) < needed:
        bits += 1

    prefix = 32 - bits

    subnet = ipaddress.ip_network((current_ip, prefix), strict=False)

    print("Hosts Required :", h)
    print("Network :", subnet.network_address)
    print("Broadcast :", subnet.broadcast_address)
    print("Subnet Mask :", subnet.netmask)
    print("Usable Hosts :", subnet.num_addresses - 2)
    print("-" * 40)

    current_ip += subnet.num_addresses