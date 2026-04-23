<svg viewBox="0 0 200 200">
	<!-- Example Square -->
		<!--
		<g transform="translate(0,0)">
			<polygon 
				points="0,0 0,10 10,10 10,0"
				fill="lightgrey"
				stroke="black"
				stroke-width="0.5"
			/> 
		</g>
		-->
	<!-- ALU -->
		<g transform="translate(100,100)">
			<polygon 
				points="0,0 8,15 32,15 40,0 22,0 20,2 18,0"
				fill="skyblue"
				stroke="black"
				stroke-width="0.5"
			/>
			<text x="16" y="10" 
				style="font: 4px sans-serif">
				ALU
			</text>
		</g>
	<!-- Register Block -->
		<g transform="translate(120,20)">
			<polygon 
				points="0,0 0,40 40,40 40,0"
				fill="lightgrey"
				stroke="black"
				stroke-width="0.5"
			/> 
			<text x="12" y="18" style="font: 4px sans-serif">
				<tspan>Register</tspan>
				<tspan dx="-13" dy="4">Block</tspan>
			</text>
			<!-- Write Port -->
				<g transform="translate(0,0)">
					<polygon 
						points="0,0 0,5 40,5 40,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="13" y="3.5" style="font: 3px sans-serif">
						Write Port
					</text>
				</g>
			<!-- Read Port A -->
				<g transform="translate(0,30)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="3" y="4.5" style="font: 3px sans-serif">
						<tspan>Read</tspan>
						<tspan dx="-8.5" dy="3">Port A</tspan>
					</text>
				</g>
			<!-- Read Port B -->
				<g transform="translate(25,30)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="3" y="4.5" style="font: 3px sans-serif">
						<tspan>Read</tspan>
						<tspan dx="-8.5" dy="3">Port B</tspan>
					</text>
				</g>
		</g>
	<!-- Decoder -->
		<g transform="translate(40,80)">
			<polygon 
				points="0,0 0,100 40,100 40,0"
				fill="lightgrey"
				stroke="black"
				stroke-width="0.5"
			/> 
			<text x="12" y="50" style="font: 4px sans-serif">
				Decoder
			</text>
		</g>
	<!-- Instruction Register -->
		<g transform="translate(10,10)">
			<polygon 
				points="0,0 0,20 75,20 75,0"
				fill="lightgrey"
				stroke="black"
				stroke-width="0.5"
			/> 
			<text x="20" y="6" style="font: 4px sans-serif">
				Instruction Register
			</text>
			<!-- Write Port -->
				<g transform="translate(0,0)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="1" y="6" style="font: 3px sans-serif">
						Write Port
					</text>
				</g>
			<!-- Opcode -->
				<g transform="translate(0,10)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="2" y="6" style="font: 3px sans-serif">
						Opcode
					</text>
				</g>
			<!-- Register A -->
				<g transform="translate(15,10)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="0.5" y="6" style="font: 3px sans-serif">
						Register A
					</text>
				</g>
			<!-- Register B -->
				<g transform="translate(30,10)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="0.5" y="6" style="font: 3px sans-serif">
						Register B
					</text>
				</g>
			<!-- Register C -->
				<g transform="translate(45,10)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="0.5" y="6" style="font: 3px sans-serif">
						Register C
					</text>
				</g>
			<!-- Immediate -->
				<g transform="translate(60,10)">
					<polygon 
						points="0,0 0,10 15,10 15,0"
						fill="grey"
						stroke="black"
						stroke-width="0.5"
					/> 
					<text x="0.5" y="6" style="font: 3px sans-serif">
						Immediate
					</text>
				</g>
		</g>
	<!-- MUX -->
		<g transform="translate(90,80)">
			<polygon 
				points="0,0 10,10 20,10 30,0"
				fill="lightgreen"
				stroke="black"
				stroke-width="0.5"
			/> 
			<text x="10.5" y="6" style="font: 4px sans-serif">
				MUX
			</text>
		</g>
</svg>
