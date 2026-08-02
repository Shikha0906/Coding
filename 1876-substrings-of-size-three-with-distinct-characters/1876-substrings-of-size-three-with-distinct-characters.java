class Solution {
    public int countGoodSubstrings(String s) {
        int l=0,c=0;
        HashMap<Character,Integer> m=new HashMap<>();
        for(int i=0;i<s.length();i++){
            m.put(s.charAt(i),m.getOrDefault(s.charAt(i),0)+1);
            if(i-l+1==3){
                if(m.size()==3)
                    c++;
                m.put(s.charAt(l),m.getOrDefault(s.charAt(l),0)-1);
                if(m.get(s.charAt(l)) == 0)
                    m.remove(s.charAt(l));
                l++;
            }
        }
    return c;
    }
}