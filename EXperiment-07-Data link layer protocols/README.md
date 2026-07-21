# Experiment 07 - Data Link Layer Protocols

## Aim

To study and implement the Data Link Layer protocols:
- Stop-and-Wait ARQ
- Go-Back-N ARQ
- Selective Repeat ARQ

---

## Theory

### 1. Stop-and-Wait ARQ

Stop-and-Wait ARQ is the simplest flow control and error control protocol. The sender transmits one frame and waits for its acknowledgment (ACK). If the ACK is received, the sender transmits the next frame. If the ACK is lost or a timeout occurs, the sender retransmits the same frame.

---

### 2. Go-Back-N ARQ

Go-Back-N ARQ uses a sliding window protocol. The sender can transmit multiple frames before receiving acknowledgments. If a frame is lost or damaged, the sender retransmits the lost frame and all subsequent frames in the current window.

---

### 3. Selective Repeat ARQ

Selective Repeat ARQ also uses a sliding window protocol. Unlike Go-Back-N, only the lost or damaged frame is retransmitted. Correctly received frames are accepted and buffered by the receiver, improving efficiency.

---

## Algorithms

### Algorithm 1: Stop-and-Wait ARQ

1. Read the number of frames.
2. Send one frame.
3. Wait for acknowledgment.
4. If ACK is received, send the next frame.
5. Otherwise, retransmit the same frame.
6. Repeat until all frames are transmitted.

---

### Algorithm 2: Go-Back-N ARQ

1. Read the number of frames and window size.
2. Send all frames in the current window.
3. Check whether any frame is lost.
4. If no frame is lost, move the window forward.
5. If a frame is lost, retransmit the lost frame and all subsequent frames in the current window.
6. Repeat until all frames are transmitted.

---

### Algorithm 3: Selective Repeat ARQ

1. Read the number of frames and window size.
2. Send all frames in the current window.
3. Check whether any frame is lost.
4. If no frame is lost, move the window forward.
5. If a frame is lost, retransmit only the lost frame.
6. Repeat until all frames are transmitted.

---

## Programs

- stop_and_wait.cpp
- go_back_n.cpp
- selective_repeat.cpp

---

## Sample Output

### Stop-and-Wait ARQ

```
Enter number of frames: 4

Sending Frame 1
ACK received

Sending Frame 2
ACK lost
Retransmitting Frame 2

ACK received

Sending Frame 3
ACK received

Sending Frame 4
ACK received

Transmission Completed Successfully.
```

---

### Go-Back-N ARQ

```
Enter number of frames: 8
Enter window size: 3

Sending Frame 1
Sending Frame 2
Sending Frame 3

Lost Frame: 2

Retransmitting...

Sending Frame 2 again
Sending Frame 3 again
```

---

### Selective Repeat ARQ

```
Enter number of frames: 8
Enter window size: 3

Sending Frame 1
Sending Frame 2
Sending Frame 3

Lost Frame: 2

Retransmitting Frame 2
```

---

## Conclusion

The Stop-and-Wait ARQ, Go-Back-N ARQ, and Selective Repeat ARQ protocols were successfully implemented. The programs demonstrate error detection, retransmission, and reliable data transfer mechanisms used in the Data Link Layer of computer networks.