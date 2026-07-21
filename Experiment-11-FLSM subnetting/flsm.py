import math
import ipaddress

network = input("Enter Network Address (e.g. 192.168.1.0/24): ")
subnets = int(input("Enter Number of Subnets: "))

net = ipaddress.ip_network(network, strict=False)

bits = math.ceil(math.log2(subnets))

new_prefix = net.prefixlen + bits

if new_prefix > 32:
    print("Invalid number of subnets.")
    exit()

print("\nSubnet Details:\n")

for i, subnet in enumerate(net.subnets(new_prefix=new_prefix), start=1):
    print(f"Subnet {i}")
    print("Network Address :", subnet.network_address)
    print("Broadcast Address :", subnet.broadcast_address)
    print("Subnet Mask :", subnet.netmask)
    print("Usable Hosts :", subnet.num_addresses - 2)
    print("-" * 40)