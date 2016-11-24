/* C 版本 */
#include <stdio.h>


int main( void )
{
    int i, c;
    for ( ; ; )
    {
        fputs("Please input an integer: ", stdout);
        scanf("%d", &i);
        
        if ( feof(stdin) || ferror(stdin) )
        {
            /* 如果用户输入文件结束标志（或文件已被读完）， */
            /* 或者发生读写错误，则退出循环              */
            
            /* do something */
            break;
        }
        /* 没有发生错误，清空输入流。                 */
        /* 通过 while 循环把输入流中的余留数据“吃”掉 */
        while ( (c = getchar()) != '\n' && c != EOF ) ;
        /* 使用 scanf("%*[^\n]"); 也可以清空输入流， */
        
        /* 不过会残留 \n 字符。 */
        
        printf("%d\n", i);
    }
    
    return 0;
}