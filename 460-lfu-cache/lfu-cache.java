class LFUCache {
    public class Node{
        int key;
        int value;
        int cnt;
        Node next;
        Node prev;

        public Node(int key, int value){
            this.key = key;
            this.value = value;
            cnt = 1;
        }
    }
    HashMap<Integer, Node> cacheMap;
    int capacity;

    //Map freq with head and tail
    HashMap<Integer, Pair<Node, Node>> freqMap;
    int minFreq; 

    public LFUCache(int capacity) {
        this.capacity = capacity;

        this.minFreq = 0;
        cacheMap = new HashMap<>();
        freqMap = new HashMap<>();
    }
    
    /*
    if not key exist return -1
    get node 
    remove node
    increase freq
    */
    public int get(int key) {
        if(!cacheMap.containsKey(key)){
            return -1;
        }

        Node node = cacheMap.get(key);

        //remove from prev
        // remove(node);
        increaseFreq(node);
        return node.value;
    }
    
    /*
    if key exist -> get node -> update value -> remove node -> increase freq
    
    */
    public void put(int key, int value) {
        if(cacheMap.containsKey(key)){
            Node node = cacheMap.get(key);
            node.value = value;
            increaseFreq(node);
            return;
        }
        // Capacity full
        if(cacheMap.size() == capacity){
            Node node = freqMap.get(minFreq).second.prev;
            cacheMap.remove(node.key);
            remove(node);

            ///Freq list is empty
            if(freqMap.get(minFreq).first.next == freqMap.get(minFreq).second){
                freqMap.remove(minFreq);
            }
        }
        Node node = new Node(key, value);
        cacheMap.put(key, node);
        add(node, 1);
        minFreq = 1;
    }

    void add(Node node, int freq){
        // Freq doesnt exist
        if(!freqMap.containsKey(freq)){
            Node head = new Node(-1, -1);
            Node tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
            freqMap.put(freq, new Pair<>(head, tail));
        }

        Node head = freqMap.get(freq).first;
        Node headNext = head.next;
        node.next = headNext;
        node.prev = head;
        head.next = node;
        headNext.prev = node;
    }

    //Remove node from List
    void remove(Node node){
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev = prev;
    }


    //Increase Freq of Node
    void increaseFreq(Node node){
        int prevFreq = node.cnt;

        node.cnt++;
        remove(node);

        //FreqList is empty -> remove key
        if(freqMap.get(prevFreq).first.next == freqMap.get(prevFreq).second){
            freqMap.remove(prevFreq);

            //If prevFreq and minFreq are equal
            if(minFreq == prevFreq) minFreq++;
        }

        add(node, node.cnt);
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */