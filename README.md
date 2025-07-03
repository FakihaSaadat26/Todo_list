# Todo_list
# Simple To-Do List Application

A feature-rich command-line to-do list application written in C++ that helps you manage your tasks efficiently with categories, completion tracking, and persistent storage.

## Features

- ✅ **Add Tasks**: Create new tasks with descriptions and categories
- 📋 **View Tasks**: Display all active (incomplete) tasks
- ✔️ **View Completed Tasks**: See all tasks you've finished
- 🎯 **Mark Tasks as Completed**: Toggle task completion status
- 🗑️ **Remove Tasks**: Delete tasks you no longer need
- 🏷️ **Filter by Category**: View tasks filtered by specific categories
- 💾 **Persistent Storage**: Automatically saves and loads tasks between sessions

## Getting Started

### Running the Application

```bash
./todo_list
```

On Windows:
```cmd
todo_list.exe
```

## Usage

When you run the application, you'll see a menu with the following options:

```
--- Simple To-Do List ---
1. Add Task
2. View Tasks
3. View Completed Tasks
4. Mark Task as Completed
5. Remove Task
6. Filter Tasks by Category
0. Exit
Choose an option:
```

### Menu Options

1. **Add Task (Option 1)**
   - Enter a task description
   - Optionally assign a category
   - Task is added to your active task list

2. **View Tasks (Option 2)**
   - Displays all incomplete tasks
   - Shows task ID, description, and category
   - Tasks are numbered for easy reference

3. **View Completed Tasks (Option 3)**
   - Shows all tasks you've marked as complete
   - Displays completion status and details

4. **Mark Task as Completed (Option 4)**
   - Select a task by its ID number
   - Toggle between completed and incomplete status
   - Completed tasks are moved to the completed list

5. **Remove Task (Option 5)**
   - Permanently delete a task by its ID
   - Removes the task from both active and completed lists

6. **Filter Tasks by Category (Option 6)**
   - Enter a category name
   - View only tasks belonging to that category
   - Helps organize tasks by project, priority, or type

7. **Exit (Option 0)**
   - Automatically saves all tasks to file
   - Closes the application gracefully
