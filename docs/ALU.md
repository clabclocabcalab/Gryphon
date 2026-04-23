<table>
	<tr>
		<th>Opcodes</th>
		<th>0b00-</th>
		<th>0b01-</th>
		<th>0b10-</th>
		<th>0b11-</th>
	</tr>
	<tr>
		<th>-00</th>
		<td></td>
		<td>And</td>
		<td>Add</td>
		<td>Multiply High Signed</td>
	</tr>
	<tr>
		<th>-01</th>
		<td></td>
		<td>Or</td>
		<td>Subtract</td>
		<td>Logical Shift Right</td>
	</tr>
	<tr>
		<th>-10</th>
		<td></td>
		<td>Exclusive Or</td>
		<td>Multiply</td>
		<td>Logical Shift Left</td>
	</tr>
	<tr>
		<th>-11</th>
		<td></td>
		<td>Not</td>
		<td>Multiply High Unsigned</td>
		<td>Arithmetic Shift Right</td>
	</tr>
</table>

Inputs:
- Opcode (4)
- Input A (32)
- Input B (32)
- Carry in (1)

Outputs:
- Result (32)
- Carry out (1)

