# Experiment 04: Hamming Code (Error Detection and Correction)

## Aim

To implement Hamming Code for single-bit error detection and correction.

---

## Theory

Hamming Code is an error-control coding technique used to detect and correct single-bit errors during data transmission.

Parity bits are inserted at positions that are powers of two (1, 2, 4, 8, ...). These parity bits are calculated using even parity.

At the receiver, parity bits are checked again to determine whether an error has occurred. If an error is detected, the incorrect bit is identified and corrected.

---

## Algorithm

### Sender

1. Read binary data.
2. Calculate the required number of parity bits.
3. Insert parity bits at positions 1, 2, 4, 8, ...
4. Calculate the parity values.
5. Display the generated Hamming Code.

### Receiver

1. Read the received Hamming Code.
2. Recalculate parity bits.
3. Determine the error position using parity checks.
4. If no error exists, display a success message.
5. Otherwise, flip the erroneous bit.
6. Display the corrected Hamming Code.

---

## Functions Used

- isPowerOfTwo()
- calculateParityBits()
- insertParityBits()
- calculateParityValues()
- sender()
- receiver()

---

## Output

### Sender

```
Enter binary data: 1011
Generated Hamming Code: 0110011
```

### Receiver

```
Enter received Hamming code: 0110111

Error detected at position: 5

Corrected Hamming Code: 0110011
```

---

## Result

Successfully implemented Hamming Code for single-bit error detection and correction using C++.