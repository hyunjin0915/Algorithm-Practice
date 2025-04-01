using System;
using System.Text;

public class Solution {
    public string solution(int age) {
        StringBuilder answer = new StringBuilder("", 3);
        string lang = "abcdefghij";
        string stAge = Convert.ToString(age);
        for(int i=0;i<stAge.Length;i++)
        {
            answer.Append(lang[stAge[i] - '0']);
        }
        return answer.ToString();
    }
}