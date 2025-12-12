class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] userMention =  new int[numberOfUsers];
        int allCount = 0;
        int[] offlineTimes = new int[numberOfUsers];
        Arrays.fill(offlineTimes, 0);
        Comparator<List<String>> comp = (List<String> a, List<String> b) -> {
            int ta = Integer.parseInt(a.get(1));
            int tb = Integer.parseInt(b.get(1));
            if(ta == tb){
                return -a.get(0).compareTo(b.get(0));
            }
            return Integer.compare(ta, tb);
        };
        Collections.sort(events, comp);
        // Comparator<int[]> pq = (int[] a, int[] b) -> {
        //     if(a[0] == b[0]) return a[1] - b[1];
        //     return a[0] - b[0];
        // };
        // PriorityQueue<int[]> pq = new PriorityQueue<>(comp);
        for(List<String> event:events){
            String type = event.get(0);
            Integer time = new Integer(event.get(1));
            String ids = event.get(2);
            // System.out.println(event);
            if(type.equals("MESSAGE")){// Mention Message
                if(ids.equals("ALL")){
                    allCount++;
                }else if(ids.equals("HERE")){// Only online
                    for(int index=0;index<numberOfUsers;index++){
                        if(offlineTimes[index] <= time){
                            userMention[index]++;
                        }
                    }
                }else{// Mention only
                    String[] idsArray = ids.split(" ");
                    // HashSet<Integer> used = new HashSet<Integer>(); 
                    for(String idStr:idsArray){
                        int id = Integer.parseInt(idStr.substring(2));
                        // if(!used.contains(id)){
                            userMention[id]++;
                            // usedx.add(id);
                        // }
                    }
                }
            }else{
                Integer id = Integer.parseInt(ids);
                // pq.add(new int[]{time + 60, id});
                offlineTimes[id] = time + 60;
            }
        }

        for(int i=0;i<numberOfUsers;i++){
            userMention[i] += allCount;
        }
        return userMention;

    }
}