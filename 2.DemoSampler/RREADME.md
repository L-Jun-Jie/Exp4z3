# DemoSampler
# Algorithms and Pseudo-Code

```
Algorithm DemoSampler(F, seed)
    while true do
        v <- pick_random(seed)
        assigns[v] <- decide_random(seed)
        conflict, assigns <- perform unit propagation
        if assigns is full then return assigns
        if conflict is found then
            bkl, conflict_clause <- conflict_analysis
            if conflict_clause is empty then return NULL
            BackTrack(bkl)
            F <- F union conflict_clause
            if F too large then
                perform Learnt Clause Deletion
```