# UART


## Introduction

UART (Universal Asynchronous Transmitter Receiver), this is the most common protocol used for full duplex serial communication. It is a single LSI (large scale integration) chip designed to perform asynchronous communication. This device sends and receives data from one system to another system.

In UART communication, two UARTs communicate directly with each other. The transmitting UART converts parallel data from a controlling device like a CPU into serial form, transmits it in serial to the receiving UART, which then converts the serial data back into parallel data for the receiving device. Only two wires are needed to transmit data between two UARTs. Data flows from the Tx pin of the transmitting UART to the Rx pin of the receiving UART:

<p align="center">
  <img width="60%" height="60%" src="img/UART-Basic-Connection-Diagram.png">
</p>

UARTs transmit data asynchronously, which means there is no clock signal to synchronize the output of bits from the transmitting UART to the sampling of bits by the receiving UART. Instead of a clock signal, the transmitting UART adds start and stop bits to the data packet being transferred. These bits define the beginning and end of the data packet so the receiving UART knows when to start reading the bits.

When the receiving UART detects a start bit, it starts to read the incoming bits at a specific frequency known as the baud rate. Baud rate is a measure of the speed of data transfer, expressed in bits per second (bps). Both UARTs must operate at about the same baud rate. The baud rate between the transmitting and receiving UARTs can only differ by about 10% before the timing of bits gets too far off.


## Protocol Format

The UART starts the communication with a start bit ‘0’. The start bit initiates the transfer of serial data and stop bit ends the data transaction.

<p align="center">
  <img width="85%" height="85%" src="img/UART-Protocol-format.png">
</p>

It is also provided with a parity bit (even or odd). Even parity bit is represented by ‘0’ (even number of 1’s) and the odd parity bit is represented by ‘1’ (odd number of 1’s).


## Transmission

The transmission of data is done using a single transmission line (TxD).  Here ‘0’ is considered as space and ‘1’ is known as mark state.


<p align="center">
  <img width="90%" height="90%" src="img/UART-Transmission-frame.png">
</p>

The transmitter sends a single bit at a time. After sending one bit, the next bit is sent. In this way, all the data bits are sent to the receiver with a predefined baud rate. There will be a certain delay in transmitting each bit. For example, to send one byte of data at 9600 baud rate, each bit is sent at 108 µsec delay. The data is added with a parity bit. So, 10 bits of data are required to send 7 bits of data.

## Reception

During the reception, RxD line (Receiver) is used for receiving the data.

<p align="center">
  <img width="90%" height="90%" src="img/UART-Receive-Frame.png">
</p>

## Steps of SPI Data Transmission

1. The transmitting UART receives data in parallel from the data bus:

<p align="center">
  <img width="40%" height="40%" src="img/Data-Transmission-Diagram-UART-Gets-Byte-from-Data-Bus.png">
</p>

2. The transmitting UART adds the start bit, parity bit, and the stop bit(s) to the data frame:

<p align="center">
  <img width="40%" height="40%" src="img/Data-Transmission-Diagram-UART-Adds-Start-Parity-ad-Stop-Bits-2.png">
</p>

3. The entire packet is sent serially from the transmitting UART to the receiving UART. The receiving UART samples the data line at the pre-configured baud rate:

<p align="center">
  <img width="40%" height="40%" src="img/Data-Transmission-Diagram-Transmitting-UART-Sends-Data-Packet-Serially-to-Receiving-UART.png">
</p>

4.  The receiving UART discards the start bit, parity bit, and stop bit from the data frame:

<p align="center">
  <img width="40%" height="40%" src="img/Data-Transmission-Diagram-UART-Removes-Start-Parity-and-Stop-Bits-2.png">
</p>

5. The receiving UART converts the serial data back into parallel and transfers it to the data bus on the receiving end:

<p align="center">
  <img width="40%" height="40%" src="img/Data-Transmission-Diagram-Receiving-UART-Sends-Byte-to-Data-Bus-2.png">
</p>



## Advantages and Disadvantages of I2C
No communication protocol is perfect, but UARTs are pretty good at what they do. Here are some pros and cons to help you decide whether or not they fit the needs of your project:

### Advantages

- Only uses two wires
- No clock signal is necessary
- Has a parity bit to allow for error checking
- The structure of the data packet can be changed as long as both sides are set up for it
- Well documented and widely used method

### Disadvantages

- The size of the data frame is limited to a maximum of 9 bits
- Doesn’t support multiple slave or multiple master systems 
- The baud rates of each UART must be within 10% of each other