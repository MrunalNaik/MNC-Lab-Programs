# Experiment 03 – Parity Bit

## Aim

To implement Even Parity and Odd Parity for single-bit error detection during data transmission.

## Theory

Parity Bit is one of the simplest error detection techniques used in computer networks. A single parity bit is appended to the data before transmission.

- **Even Parity:** Total number of 1s (including the parity bit) should be even.
- **Odd Parity:** Total number of 1s (including the parity bit) should be odd.

The receiver counts the number of 1s in the received frame to determine whether an error has occurred.

## Algorithm

### Sender

1. Read the binary data.
2. Select Even or Odd parity.
3. Count the number of 1s.
4. Generate the parity bit.
5. Append the parity bit to the data.
6. Transmit the frame.

### Receiver

1. Read the received frame.
2. Select the parity type.
3. Count the number of 1s.
4. Verify whether the parity condition is satisfied.
5. Display whether an error is detected.

## Functions Used

- `countOnes()`
- `generateParityBit()`
- `sender()`
- `receiver()`

## Sample Output

### Sender

```
Enter Data Bits: 1011011

Choose Parity
1. Even
2. Odd

Choice: 1

Parity Bit: 1
Transmitted Frame: 10110111
```

### Receiver (No Error)

```
Enter Received Frame: 10110111

Choose Parity
1. Even
2. Odd

Choice: 1

No Error Detected
```

### Receiver (Error)

```
Enter Received Frame: 10110011

Choose Parity
1. Even
2. Odd

Choice: 1

Error Detected
```

## Result

The parity bit algorithm was successfully implemented and tested for error detection.