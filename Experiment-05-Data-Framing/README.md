# Experiment 05 - Data Framing

## Aim

To implement different Data Framing techniques used in Computer Networks.

## Programs

1. Character Count
2. Byte Stuffing
3. Bit Stuffing
4. Physical Layer Violation

## Description

### Character Count
Each frame begins with a count field indicating the number of characters in the frame.

### Byte Stuffing
Special FLAG and ESC characters are used. Whenever FLAG or ESC appears in the data, an ESC character is inserted before it.

### Bit Stuffing
A `0` is inserted after every five consecutive `1`s in the data. The frame is enclosed using the flag sequence `01111110`.

### Physical Layer Violation
Frames are identified using a special violation pattern that does not occur during normal data transmission.

## Language Used

- C++

## Concepts Covered

- Data Link Layer
- Framing Techniques
- Character-Oriented Framing
- Bit-Oriented Framing
- Physical Layer Framing