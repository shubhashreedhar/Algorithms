/* Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
 * If S[i] == "I", then A[i] < A[i+1]
 * If S[i] == "D", then A[i] > A[i+1]
 * Input: "IDID"
 * Output: [0,4,1,3,2]
 */

vector<int> diStringMatch(string S) {
        vector<int> v;
        int no_of_next_D = 0; //Implies the no of D's after this index
        int cur_max, last_entry = 0;
        int j;
        
        for(int i=0; i < S.length(); i++)
        {            
            switch(S[i])
            {   
                case 'I':
                    no_of_next_D = 0;
                    j = i+1;
                    while(S[j] == 'D' && j < S.length())
                    {
                        no_of_next_D++;
                        j++;
                    }
                    
                    if(i == 0)
                    {
                        cur_max = no_of_next_D + 1;
                        v.push_back(last_entry);
                        v.push_back(cur_max);
                        
                        last_entry = cur_max;
                    }
                    else
                    {
                        //+1 is added so that repeation of the digits is avoided
                        cur_max  = cur_max + no_of_next_D + 1;
                        last_entry = cur_max;
                        v.push_back(last_entry);
                    }
                    
                    for(int k = 0; k < no_of_next_D; k++)
                    {
                        v.push_back(--last_entry);
                        i++;
                    }
                    break;
                    
                case 'D':
                    
                    no_of_next_D = 0;
                    j = i+1;
                    while(S[j] == 'D' && j < S.length())
                    {
                        no_of_next_D++;
                        j++;
                    }
                    if(i == 0)
                    {                          
                        cur_max = no_of_next_D + 1;
                        last_entry = cur_max;
                        
                        //For the starting number compared to which the first D will be printed
                        v.push_back(last_entry--);
                        //For first D
                        v.push_back(last_entry--);
                    }
                    else
                    {
                        v.push_back(last_entry--);
                    }
                        
            }
        }
        return v;
    }
