using System;
using System.Collections;
namespace _PA2
{
    public class HuffmanDecoder
    {
        public static String decode(String encodedMsg, Hashtable encodingToCharMapping)
        {   // complete this function
            string encode = "";
            string decodedMsg = "";
            int n = encodedMsg.Length;
            for (int i = 0; i < n; i++)
            {
                encode = encode + encodedMsg[i];
                if (encodingToCharMapping.ContainsKey(encode))
                {
                    encodingToCharMapping.Add(encode, 'c');
                    decodedMsg = decodedMsg + 'c';
                    encode = "";
                }
            }
            return decodedMsg;
        }
    }
}
