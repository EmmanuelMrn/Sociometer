void delay( void )
{
   volatile int j,k;
   j=256;
   do{
      k=500;
	  do{
		__asm( "nop" );
	    __asm( "nop" );
		__asm( "nop" );
		__asm( "nop" );
		
	  }while(--k);
   }while(--j);
}

void delay1seg( void )
{	
	do
	{
		volatile int m=0, n=0,x=0, mseg=1000;
		do
		{
			do
			{
				do
				{
				
					x++;
				}while(x<=400);
		
				
				n++;
			}while(n<=410);
		
			m ++;
		}while(m<=413);

		mseg--;
	}while(1000);
}