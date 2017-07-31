/*

1. Create two Table
	a.       Employee Master ( Name – EMPLOYEE_MST)
	b.      Department Employee Master (NAME – DEPT_EMPL_MST)

2. Column Name for each Table as below

a. Employee Master

Column Name			Data Type		Width
-------------------------------------------
Employee_id			Number
Employee_name		Varchar			30
DOB					Date
Manager_id			Number
PAN_NO				VARCHAR			10



Create Primary key on Employee_id

Enter at least 6 data

Value of Manager_id will be value of Employee_id

Also note that do not put same employee_Id in Manager_id

 

b. Department Employee Master

Column Name			Data Type			Width
Dept_id				Number
Department_name		Varchar				30
Employee_id			Number

Create primary key on Dept_id

Enter at least  6 data

For one record do not enter Employee_id


3. Now try the following query
	a. Display Employee_id,Employee_name,dept_id,department_name using inner joim
	b. Write Left outer join and right outer join using Employee Master and Department Employee Master
	c. Write Self Join on Employee Master and show Employee_id,Employee Name,ManagerId and Manager Name
*/

CREATE DATABASE IF NOT EXISTS DBMS;

USE DBMS;

DROP TABLE IF EXISTS EMPLOYEE_MST;
CREATE TABLE EMPLOYEE_MST(
	Employee_id INT,
	Employee_name VARCHAR(30) PRIMARY KEY,
	DOB DATE,
	Manager_id INT,
	PAN_NO VARCHAR(10)
);


DROP TABLE IF EXISTS DEPT_EMPL_MST;
CREATE TABLE DEPT_EMPL_MST(
	Dept_id INT PRIMARY KEY,
	Department_name VARCHAR(30),
	Employee_id INT
);

INSERT INTO EMPLOYEE_MST VALUES(1, "CEO", DATE("1956-4-23"), -1, 'CEOPAN1234');
INSERT INTO EMPLOYEE_MST VALUES(2, "CTO", DATE("1956-4-25"), 1, 'CTOPAN1234');
INSERT INTO EMPLOYEE_MST VALUES(3, "VP1", DATE("1966-4-23"), 1, 'VP1PAN1234');
INSERT INTO EMPLOYEE_MST VALUES(4, "VP2", DATE("1976-3-22"), 1, 'VP2PAN1234');
INSERT INTO EMPLOYEE_MST VALUES(5, "DIRECTOR1", DATE("1959-8-21"), 3, 'DI1PAN1234');
INSERT INTO EMPLOYEE_MST VALUES(6, "DIRECTOR2", DATE("1977-7-11"), 4, 'DI2PAN1234');
INSERT INTO EMPLOYEE_MST VALUES(7, "MANAGER1", DATE("1979-1-23"), 5, 'MG1PAN1234');

INSERT INTO DEPT_EMPL_MST VALUES(1, 'DEPT1', 1);
INSERT INTO DEPT_EMPL_MST VALUES(2, 'DEPT2', 2);
INSERT INTO DEPT_EMPL_MST VALUES(3, 'DEPT3', 3);
INSERT INTO DEPT_EMPL_MST VALUES(4, 'DEPT4', 4);
INSERT INTO DEPT_EMPL_MST VALUES(5, 'DEPT5', 5);
INSERT INTO DEPT_EMPL_MST VALUES(6, 'DEPT6', 6);
INSERT INTO DEPT_EMPL_MST VALUES(7, 'DEPT7', NULL);


-- Display Employee_id,Employee_name,dept_id,department_name using inner joim
SELECT E.Employee_id, E.Employee_name, D.Dept_id, D.Department_name FROM EMPLOYEE_MST E INNER JOIN DEPT_EMPL_MST D ON D.Employee_id = E.Employee_id;

-- Write Left outer join and right outer join using Employee Master and Department Employee Master
SELECT E.Employee_id, E.Employee_name, D.Dept_id, D.Department_name FROM EMPLOYEE_MST E LEFT JOIN DEPT_EMPL_MST D ON D.Employee_id = E.Employee_id;
SELECT E.Employee_id, E.Employee_name, D.Dept_id, D.Department_name FROM EMPLOYEE_MST E RIGHT JOIN DEPT_EMPL_MST D ON D.Employee_id = E.Employee_id;

-- Write Self Join on Employee Master and show Employee_id,Employee Name,ManagerId and Manager Name
SELECT E1.Employee_id as 'Employee ID', E1.Employee_name as 'Employee Name', E2.Employee_id as 'Manager Id', E2.Employee_name as 'Manager Name' 
from EMPLOYEE_MST E1 INNER JOIN EMPLOYEE_MST E2
ON E1.Manager_id = E2.Employee_id