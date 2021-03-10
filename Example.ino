#include "samsUSART.h"
#include <util/delay.h>

int main(void)
{
    USART0.begin(9600);

    USART0.Writeln("--------------------");
    USART0.Writeln("Hello World");
    USART0.Writeln("--------------------");
    
    while(1)
    {
        USART0.Writeln("tick");
        _delay_ms(1000);
        USART0.Writeln("tock");
        _delay_ms(1000);
    };
    return 1;
}
