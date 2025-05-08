USE software;
CREATE TABLE events (
    event_id    INT PRIMARY KEY AUTO_INCREMENT,  -- 事件ID（主键）
    title       VARCHAR(100) NOT NULL,           -- 事件标题
    description TEXT,                            -- 事件描述
    start_time  VARCHAR(100) NOT NULL,               -- 事件开始时间
    end_time    VARCHAR(100) NOT NULL,               -- 事件结束时间
    priority    ENUM('Low', 'Medium', 'High') DEFAULT 'Medium', -- 事件优先级events
    status      ENUM('Pending', 'In Progress', 'Completed') DEFAULT 'Pending', -- 任务状态
    created_at  VARCHAR(100) -- 日期
);

set sql_safe_updates = 0;
delete from events;
set sql_safe_updates = 1;

select *
from events;

CREATE TABLE users (
    user_id     INT PRIMARY KEY AUTO_INCREMENT,  -- 用户ID（主键）
    username    VARCHAR(50) UNIQUE NOT NULL,     -- 用户名
    password    VARCHAR(255) NOT NULL,           -- 密码（建议加密存储）
    email       VARCHAR(100) UNIQUE,             -- 邮箱
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP -- 账户创建时间
);
CREATE TABLE reminders (
    reminder_id INT PRIMARY KEY AUTO_INCREMENT,  -- 提醒ID
    event_id    INT NOT NULL,                    -- 关联事件ID
    remind_time DATETIME NOT NULL,               -- 提醒时间
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 创建时间
    FOREIGN KEY (event_id) REFERENCES events(event_id) ON DELETE CASCADE
);
CREATE TABLE notes (
    note_id     INT PRIMARY KEY AUTO_INCREMENT,  -- 笔记ID
    user_id     INT NOT NULL,                    -- 关联用户ID
    title       VARCHAR(100),                    -- 笔记标题
    content     TEXT NOT NULL,                   -- 笔记内容
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 创建时间
    updated_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP, -- 更新时间
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE
);
CREATE TABLE habits (
    habit_id    INT PRIMARY KEY AUTO_INCREMENT,  -- 习惯ID
    user_id     INT NOT NULL,                    -- 关联用户ID
    habit_name  VARCHAR(100) NOT NULL,           -- 习惯名称
    frequency   ENUM('每日', '每周', '每月') NOT NULL, -- 习惯频率
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 创建时间
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE
);
