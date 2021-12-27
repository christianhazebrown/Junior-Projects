#Created by christian brown
from time import sleep
from selenium import webdriver
from instapy import InstaPy
import datetime
#-----------------------------------------------------------------------------------------------------------
# global variables used for TIME
TIME = datetime.datetime.now()
HOUR = TIME.hour
MIN = TIME.minute
SEC = TIME.second
print('Time is Hour:', HOUR, '\nMIN', MIN)
#-----------------------------------------------------------------------------------------------------------
user_time = input('How long would you like to run the bot (hours):')


def login_test():
    #sets the web diver web browser as chrome
    browser = webdriver.Firefox()
    browser.implicitly_wait(5)

    #this opens the browser and goes to instragram.com
    browser.get("https://www.instagram.com/")

    # finds the login area for the user/pass by the class
    login_link = browser.find_element_by_class_name('-MzZI')
    login_link.click()

    # finds the area to enter value of user/pass
    username_input = browser.find_element_by_css_selector("input[name='username']")
    password_input = browser.find_element_by_css_selector("input[name='password']")

    #stores username and password for instagram log in and prints in the user/login
    username_input.send_keys("")
    password_input.send_keys("")

    #press enter button for instagram website
    login_button = browser.find_element_by_xpath("//button[@type='submit']")
    login_button.click()

    #checks errors
    errors = browser.find_elements_by_css_selector('#error_message')
    assert len(errors) == 0

    #this pauses the program for 5 secounds
    sleep(15)

    #closes the indicated browser
    browser.close()



while (HOUR <= HOUR + int(user_time)):
    #add instagram user name and password here to allow the bot to login
    bot = InstaPy(username="", password="").login()

    bot.set_relationship_bounds(enabled=True, max_followers=1000)

    bot.set_quota_supervisor(enabled=True, peak_comments_daily=240, peak_comments_hourly=21)


    bot.like_by_tags(["film","drone"], amount=2)
    bot.set_dont_like(["naked", "nsfw"])

    bot.set_do_follow(True, percentage=50, times=2)

    bot.set_do_comment(True, percentage=25)
    bot.set_comments(['Nice! :heart_eyes:','Follow for follow?','Check out mine!'])

    bot.end()

    HOUR = TIME.hour
