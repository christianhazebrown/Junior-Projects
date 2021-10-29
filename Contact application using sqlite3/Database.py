import sqlite3
from sqlite3 import Error

def create_table():
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute('CREATE TABLE IF NOT EXISTS contact(name TEXT, number TEXT)')
  c.close()
  conn.close()

def data_entry(name, number):
  name.upper()
  create_table()
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute("INSERT INTO contact VALUES(?,?)", (name.upper(), number))
  conn.commit()
  c.close()
  conn.close()

def data_retrive(name):
  create_table()
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute("SElECT * FROM contact")
  #stores data from table
  contacts = c.fetchall()
  for contact in contacts:
    if name == contact[0]:
      return contact[1]
  c.close()
  conn.close()
  return False

def delete_contact(name):
  create_table()
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute("SElECT * FROM contact")
  contacts = c.fetchall()
  c.execute("SELECT * FROM contact WHERE name = ?", (name,))
  contact = c.fetchone()
  if contact == None:
    c.close()
    conn.close()
    return False
  elif contact[0] == name:
    c.execute("DELETE FROM contact WHERE name = ?", (name,))
    conn.commit()
    c.close()
    conn.close()
    return True
  else:
    c.close()
    conn.close()
    return False

def update_contact(name, number):
  create_table()
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute("SELECT * FROM contact WHERE name = ?", (name,))
  contact = c.fetchone()
  if contact == None:
    c.close()
    conn.close()
    return False
  elif contact[0] == name:
    c.execute("UPDATE contact SET number = ? WHERE name = ? ", (number,name))
    conn.commit()
    c.close()
    conn.close()
    return True
  else:
    c.close()
    conn.close()
    return False

def list_all():
  create_table()
  conn = sqlite3.connect('database.db')
  c = conn.cursor()
  c.execute("SElECT * FROM contact")
  contacts = c.fetchall()
  for contact in contacts:
    print(contact[0], "   ", contact[1])
  c.close()
  conn.close()