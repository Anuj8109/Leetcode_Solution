class Solution {
    public int bestClosingTime(String customers) {
        int countN = 0;
        for(char c:customers.toCharArray()){
            if(c == 'N') countN++;
        }

        int result = countN;
        int closingHour = customers.length();
        int countY = 0;
        for(int i=customers.length()-1;i>=0;i--){
            if(customers.charAt(i) == 'Y') countY++;
            else countN--;
            int penalty = countN + countY;
            if(result >= penalty){
                closingHour = i;
                result = penalty;
            }
        }
        return closingHour;
    }
}