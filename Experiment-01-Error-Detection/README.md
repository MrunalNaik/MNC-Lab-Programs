# Experiment 01 - Error Detection using Checksum

## Aim
To implement the Checksum Error Detection technique using 1's Complement Addition.

## Algorithm
### Sender
1. Read two binary words.
2. Perform binary addition.
3. Apply end-around carry.
4. Find the one's complement of the sum.
5. Transmit the data and checksum.

### Receiver
1. Read the received data and checksum.
2. Perform binary addition.
3. Add the checksum.
4. If the final result is all 1's, no error is detected.
5. Otherwise, an error is detected.

## Language
- C++

## Concepts Used
- Binary Addition
- One's Complement
- End-around Carry
- Error Detection