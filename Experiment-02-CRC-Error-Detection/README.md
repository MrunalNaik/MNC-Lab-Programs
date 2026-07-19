# Experiment 02 – CRC (Cyclic Redundancy Check)

## Aim

To implement the CRC (Cyclic Redundancy Check) algorithm for error detection during data transmission.

## Theory

CRC is an error detection technique used in computer networks. The sender performs modulo-2 division on the data using a generator polynomial and appends the remainder (CRC bits) to the original data before transmission.

The receiver performs the same modulo-2 division on the received frame.

- If the remainder is all zeros, no error is detected.
- Otherwise, an error is detected.

## Algorithm

### Sender

1. Read the data bits.
2. Read the generator polynomial.
3. Append `(generator length - 1)` zeros to the data.
4. Perform modulo-2 division.
5. Append the remainder to the original data.
6. Transmit the frame.

### Receiver

1. Read the received frame.
2. Read the generator polynomial.
3. Perform modulo-2 division.
4. If the remainder is all zeros, accept the frame.
5. Otherwise, report an error.

## Functions Used

- `modulo2Division()`
- `generateCRC()`
- `checkCRC()`
- `sender()`
- `receiver()`

## Sample Output

### Sender

```
Enter Data Bits: 1101011011
Enter Generator Polynomial: 10011

Transmitted Frame: 11010110111110
```

### Receiver (No Error)

```
Enter Received Frame: 11010110111110
Enter Generator Polynomial: 10011

No Error Detected
```

### Receiver (With Error)

```
Enter Received Frame: 11010110110110
Enter Generator Polynomial: 10011

Error Detected
```

## Result

The CRC algorithm was successfully implemented and tested for error detection.