use software;



CREATE TABLE reminders (

    event_id INT PRIMARY KEY AUTO_INCREMENT,
    remind_before INT unsigned,
    remind_start BOOLEAN NOT NULL DEFAULT FALSE,
    remind_end BOOLEAN NOT NULL DEFAULT FALSE,
is_shown_start BOOLEAN DEFAULT FALSE,       
    is_shown_deadline BOOLEAN DEFAULT FALSE,    

    FOREIGN KEY (event_id) REFERENCES events(event_id) ON DELETE CASCADE
);

select *from reminders;