const char html_wifi_config[] PROGMEM = R"rawliteral(
    
    <!DOCTYPE html>
    <html lang="en">
      <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <style>
          body {
            font-family: Arial, sans-serif;
            background-color: #90e8f2;
            margin: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
          }
    
          form {
            background-color: #28d9ed;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 390px;
          }
    
          h3 {
            text-align: center;
            color: #333;
          }
          h1 {
            text-align: center;
            color: #637e76;
          }
    
          .main-reading,
          .single-digit {
            margin-bottom: 16px;
          }
    
          .main-reading input,
          .single-digit input {
            width: 100%;
            padding: 10px;
            box-sizing: border-box;
            margin-right: 8px;
            border: 1px solid #ccc;
            border-radius: 4px;
            text-align: center;
          }
    
          .single-digit input {
            margin-right: 0;
          }
    
          button {
            background-color: #4caf50;
            color: #fff;
            padding: 10px 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            width: 100%;
          }
    
          button:hover {
            background-color: #45a049;
          }
        </style>
      </head>
      <body>
        <div>
          <h1>WiFi Config</h1>
          <form action="/get_wifi_config">
            <h3>SSID</h3>
            <div class="main-reading">
              <input type="text" name="form_ssid" required />
            </div>
            <h3>PASSWORD</h3>
            <div class="single-digit">
              <input type="text" name="form_password" required />
            </div>
    
            <button type="submit">Submit</button>
          </form>
        </div>
      </body>
    </html>

)rawliteral";