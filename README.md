# avr-USART
Simple Serial (USART) communication for Arduino

Written for and tested on a ATMEGA2560

## Usage
To use the library, clone or download it to your project directory and
```c
#include "avrUSART/USART.h"
```
## Pre-definitions
USART0 through USART3 are conditionally defined in `samsUSART.h`. It is recommended to use these rather than instantiating a new USART object. 

If you wish to access other USART ports, you will have to instantiate them yourself.

`USART0` is usually tied to the board's USB port

## Functions

### Constructor
<table>
	<tr>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>USART USART(n)</code></td>
		<td>
			A macro for instanciating a new USART port. The following are assumed defined:
			<ul>
				<li><code>UBBRnL</code></li>
				<li><code>UBRRnH</code></li>
				<li><code>UCSRnA</code></li>
				<li><code>UCSRnB</code></li>
				<li><code>UCSRnC</code></li>
				<li><code>UDRN</code></li>
			</ul>
		</td>
	</tr>
</table>

### Core Functions
<table>
	<tr>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>void begin(ulong)</code></td>
		<td>
			Sets baud rate to that provided, as well as the following:
			<ul>
				<li>Frame Size = 8</li>
				<li>Stop Bits = 1</li>
				<li>Parity = Disabled</li>
				<li>Tx = Enabled</li>
				<li>Rx = Enabled</li>
			</ul>
		</td>
	</td>
	</tr>
	<tr>
		<td><code>char Read()</code></td>
		<td>Reads the current character in the USART's data register</td>
	</tr>
	<tr>
		<td><code>void Write(char)</code></td>
		<td>Writes a character to the USART's data register. Blocked until the data register is empty</td>
	</tr>
	<tr>
		<td><code>void Write(char*)</code></td>
		<td>Sequentially writes a cstring to the data register (must be null terminated)</td>
	</tr>
	<tr>
		<td><code>void SetBaudRate(ulong)</code></td>
		<td>Sets the USART port's baud rate</td>
	</tr>
</table>

### UCSRA Functions
<table>
	<tr>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>bool RxComplete()</code></td>
		<td>Returns <code>true</code> if the <code>RxC</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>bool TxComplete()</code></td>
		<td>Returns 1 if the <code>TxC</code> flag is set, 0 otherwise</td>
	</tr>
	<tr>
		<td><code>void SetTxComplete()</code></td>
		<td>Sets the <code>TxC</code> flag</td>
	</tr>
	<tr>
		<td><code>void ClearTxComplete()</code></td>
		<td>Clears the <code>TxC</code> flag</td>
	</tr>
	<tr>
		<td><code>bool DataRegisterEmpty()</code></td>
		<td>Returns <code>true</code> if the <code>UDRE</code> flag is set, amd <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>bool FrameError()</code></td>
		<td>Returns <code>true</code> if the <code>FE</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>bool DataOverrunError()</code></td>
		<td>Returns <code>true</code> if the <code>DOR</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>bool ParityError()</code></td>
		<td>Returns <code>true</code> if the <code>PE</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>bool DoubleTransmissionSpeedIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>U2X</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableDoubleTransmissionSpeed()</code></td>
		<td>Sets the <code>U2X</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableDoubleTransmissionSpeed()</code></td>
		<td>Clears the <code>U2X</code> flag</td>
	</tr>
	<tr>
		<td><code>bool MultiProcessorCommunicationModeIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>MPCM</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableMultiProcessorCommunicationMode()</code></td>
		<td>Sets the <code>MPCM</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableMultiProcessorCommunicationMode()</code></td>
		<td>Clears the <code>MPCM</code> flag</td>
	</tr>
</table>

### UCSRB Functions
<table>
	<tr>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>bool RxCompleteInterruptIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>RXCIE</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableRxCompleteInterrupt()</code></td>
		<td>Sets the <code>RXCIE</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableRxCompleteInterrupt()</code></td>
		<td>Clears the <code>RXCIE</code> flag</td>
	</tr>
	<tr>
		<td><code>bool TxCompleteInterruptIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>TXCIE</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableTxCompleteInterrupt()</code></td>
		<td>Sets the <code>TXCIE</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableTxCompleteInterrupt()</code></td>
		<td>Clears the <code>TXCIE</code> flag</td>
	</tr>
	<tr>
		<td><code>bool DataRegisterEmptyInterruptIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>UDRIE</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableDataRegisterEmptyInterrupt()</code></td>
		<td>Sets the <code>UDRIE</code> flag</td>
	</tr>
	<tr>
		<td><code>void EnableDataRegisterEmptyInterrupt()</code></td>
		<td>Clears the <code>UDRIE</code> flag</td>
	</tr>
	<tr>
		<td><code>bool RxIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>RXEN</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableRx()</code></td>
		<td>Sets the <code>RXEN</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableRx()</code></td>
		<td>Clears the <code>RXEN</code> flag</td>
	</tr>	
	<tr>
		<td><code>bool TxIsEnabled()</code></td>
		<td>Returns <code>true</code> if the <code>TXEN</code> flag is set, and <code>false</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void EnableTx()</code></td>
		<td>Sets the <code>TXEN</code> flag</td>
	</tr>
	<tr>
		<td><code>void DisableTx()</code></td>
		<td>Clears the <code>TXEN</code> flag</td>
	</tr>
	<tr>
		<td><code>byte GetRxBit9</code></td>
		<td>Returns <code>1</code> if the <code>RXB8</code> is set, and <code>0</code> otherwise</td>
	</tr>
	<tr>
		<td><code>byte GetTxBit9()</code></td>
		<td>Returns <code>1</code> if the <code>TXB8</code> is set, and <code>0</code> otherwise</td>
	</tr>
	<tr>
		<td><code>void SetTxBit9()</code></td>
		<td>Sets <code>TXB8</code></td>
	</tr>
	<tr>
		<td><code>void ClearTxBit9()</code></td>
		<td>Clears <code>TXB8</code></td>
	</tr>
</table>

### UCSRC Functions
<table>
	<tr>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td><code>USART::Mode GetMode()</code></td>
		<td>Returns which mode of operation the USART port is in</td>
	</tr>
	<tr>
		<td><code>void SetMode(USART::Mode)</code></td>
		<td>Sets the USART port's mode of operation</td>
	</tr>
	<tr>
		<td><code>USART::Parity GetParity()</code></td>
		<td>Returns which parity mode the USART port is in</td>
	</tr>
	<tr>
		<td><code>void SetParity(USART::Parity)</code></td>
		<td>Sets the USART port's parity mode</td>
	</tr>
	<tr>
		<td><code>USART::StopBits GetStopBits()</code></td>
		<td>Returns how many stop bits the USART port is using for communication</td>
	</tr>
	<tr>
		<td><code>void SetStopBits(USART::StopBits)</code></td>
		<td>Sets how many stop bits the USART port will use for communication</td>
	</tr>
	<tr>
		<td><code>USART::FrameSize GetFrameSize()</code></td>
		<td>Returns the frame size the USART port is using for communication</td>
	</tr>
	<tr>
		<td><code>SetFrameSize(USART::FrameSize)</code></td>
		<td>Sets the frame size the USART port will use for communication</td>
	</tr>
	<tr>
		<td><code>USART::ClockPolarity GetClockPolarity()</code></td>
		<td>Returns the clock polarity mode the USART port is using for communication</td>
	</tr>
	<tr>
		<td><code>void SetClockPolarity(USART::ClockPolarity)</code></td>
		<td>Sets the clock polarity mode the USART port will use for communication</td>
	</tr>
</table>

### Enums
<table>
	<tr>
		<th>Name</th>
		<th>Values</th>
	</tr>
	<tr>
		<td><code>USART::Mode</code></td>
		<td>
			<ul>
				<li><code>ASYNC</code></li>
				<li><code>SYNC</code></li>
				<li><code>MSPIM</code> (Master SPI Mode)</li>
			</ul>				
		</td>
	</tr>
	<tr>
		<td><code>USART::Parity</code></td>
		<td>
			<ul>
				<li><code>DISABLED</code></li>
				<li><code>RESERVED</code></li>
				<li><code>EVEN</code></li>
				<li><code>ODD</code></li>
			</ul>				
		</td>
	</tr>
	<tr>
		<td><code>USART::StopBits</code></td>
		<td>
			<ul>
				<li><code>ONE</code></li>
				<li><code>TWO</code></li>
			</ul>				
		</td>
	</tr>
	<tr>
		<td><code>USART::FrameSize</code></td>
		<td>
			<ul>
				<li><code>FIVE</code></li>
				<li><code>SIX</code></li>
				<li><code>SEVEN</code></li>
				<li><code>EIGHT</code></li>
				<li><code>NINE</code></li>
			</ul>				
		</td>
	</tr>
	<tr>
		<td><code>USART::ClockPolarity</code></td>
		<td>
			<ul>
				<li><code>RISING_EDGE</code></li>
				<li><code>FALLING_EDGE</code></li>
			</ul>				
		</td>
	</tr>
</table>


## Supported Boards
- ATMEGA2560

(may still work on others)

# Limitations
- Need some familiarity with USART
