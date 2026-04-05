class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleet = 1

        pos_speed = [p_s for p_s in zip(position, speed)]
        
        pos_speed.sort(key = lambda p_s : -p_s[0])

        curr_last_arrival = (target - pos_speed[0][0]) / pos_speed[0][1]

        for pos, speed in pos_speed:
            print(f"curr = {curr_last_arrival} and new = {(target - pos) / speed}")
            if curr_last_arrival < (target - pos) / speed:
                fleet += 1
                curr_last_arrival = (target - pos) / speed

        return fleet