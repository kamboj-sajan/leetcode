-- Last updated: 19/08/2026, 15:37:43
-- Select 
-- a.machine_id ,
-- ROUND(AVG(b.timestamp - a.timestamp),3) AS processing_time
-- From Activity a
-- JOIN Activity b
-- On a.machine_id = b.machine_id
-- And a.process_id = b.process_id
-- Where a.activity_type = 'start'
-- And b.activity_type = 'end'
-- Group BY a.machine_id;

select 
machine_id,
Round(AVG(process_time),3) as processing_time
From (
    Select 
    machine_id,
    process_id,
    SUM(
        Case
        When activity_type = 'end' then timestamp
        else -timestamp
        end
    )AS process_time
    From Activity
    Group BY machine_id,process_id
)t
Group BY machine_id;