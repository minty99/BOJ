import Foundation

let n : Int = Int(readLine()!)!
let s : Int = Int(readLine()!)!
var from: [Int] = []
var to: [Int] = []

for i in 0..<s {
    var line = readLine()!
    var sp = line.components(separatedBy: " ")
    from.append(Int(sp[0])!)
    to.append(Int(sp[1])!)
}

var status = [Bool](repeating: false, count: n+1)
var count : Int = 0
status[1] = true
var queue : [Int] = [1]
var ptr : Int = 0

while queue.count > ptr {
    for i in 0..<s {
        if from[i] == queue[ptr] {
            if status[to[i]] == false {
                count += 1
                queue.append(to[i])
            }
            status[to[i]] = true
        }
        
        if to[i] == queue[ptr] {
            if status[from[i]] == false {
                count += 1
                queue.append(from[i])
            }
            status[from[i]] = true
        }
    }
    ptr += 1
}

print(count)
