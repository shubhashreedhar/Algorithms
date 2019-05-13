/* Given two integers A and B, return any string S such that:
 * S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
 * The substring 'aaa' does not occur in S;
 * The substring 'bbb' does not occur in S.
 */

string strWithout3a3b(int A, int B) {
        string str;
        while(A>0 || B>0)
        {
            bool writeA = false;
            int L = str.length();
            if(L>=2 && str[L-1] == str[L-2])
            {
                if(str[L-1] == 'b')
                    writeA = true;
            }
            else
            {
                if(A>=B)
                    writeA = true;
            }

            if(writeA)
            {
                A--;
                str.append("a");
            }
            else
            {
                B--;
                str.append("b");
            }
        }
        return str;
}
