class TimeMap:

    def __init__(self):
        self.time_map = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.time_map[key].append((value, timestamp))
        

    def get(self, key: str, timestamp: int) -> str:
        l = 0
        r = len(self.time_map[key]) - 1

        time_stamp_list = self.time_map[key]
        if len(time_stamp_list) > 0 and time_stamp_list[l][1] <= timestamp:
            res = time_stamp_list[l][0]
        else:
            return ""
        while l <= r:
            mid = (r - l) // 2 + l
            
            if time_stamp_list[mid][1] == timestamp:
                return time_stamp_list[mid][0]
            
            if time_stamp_list[mid][1] <= timestamp:
                res = time_stamp_list[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        
        return res


        
