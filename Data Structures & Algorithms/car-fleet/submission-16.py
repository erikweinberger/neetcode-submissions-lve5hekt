class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pos_speed = [(p, s) for p, s in zip(position, speed)]
        pos_speed.sort(key=lambda x: -x[0])
        
        fleet = 1
        slowest_time = (target - pos_speed[0][0]) / pos_speed[0][1]

        for p, s in pos_speed[1:]:
            curr_time = (target - p) / s
            if curr_time > slowest_time:
                fleet += 1
                slowest_time = curr_time
        
        return fleet