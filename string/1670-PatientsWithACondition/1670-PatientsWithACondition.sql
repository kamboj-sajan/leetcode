-- Last updated: 19/08/2026, 15:46:25
SELECT
    patient_id,
    patient_name,
    conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%'
   OR conditions LIKE '% DIAB1%';