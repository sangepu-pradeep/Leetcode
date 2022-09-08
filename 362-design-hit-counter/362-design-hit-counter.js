
var HitCounter = function() {
        this.hitObj = {};
};

/** 
 * @param {number} timestamp
 * @return {void}
 */
HitCounter.prototype.hit = function(timestamp) {
    if(!this.hitObj[timestamp]){
        this.hitObj[timestamp]=0;
    }
      return ++this.hitObj[timestamp];
};

/** 
 * @param {number} timestamp
 * @return {number}
 */
HitCounter.prototype.getHits = function(timestamp) {
    let count = 0;
    for(let [key, value] of Object.entries(this.hitObj)){
        if(key >= timestamp-299 && key<=timestamp){
            count+=this.hitObj[key];
        }
            
    }
    
    return count;
};

/** 
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */