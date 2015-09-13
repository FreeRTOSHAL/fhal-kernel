SECTIONS {
	.text.freertos : 
	{
		*(.text*)
		*(.rodata*)
	}
	.data.freertos :
	{
		*(.data*)
	}
	.bss.freertos : 
	{
		*(bss*)
	}
}
