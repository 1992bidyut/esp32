const char warning[] PROGMEM = R"rawliteral(

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

      .warning-container {
        background-color: #28d9ed; /* Light red */
        border: 1px solid #f5c6cb; /* Darker red */
        color: #721c24; /* Dark text color */
        padding: 15px;
        border-radius: 8px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        width: 300px;
        text-align: center;
      }

      .warning-icon {
        font-size: 24px;
        margin-bottom: 10px;
      }

      button {
        background-color: #dc3545; /* Red */
        color: #fff;
        padding: 10px 15px;
        border: none;
        border-radius: 4px;
        cursor: pointer;
      }

      button:hover {
        background-color: #c82333; /* Darker red */
      }
    </style>
  </head>
  <body>
    <div class="warning-container">
      <span class="warning-icon">&#9888;</span>
      <!-- Warning sign icon -->
      <p>Somethings Wrorng!!!</p>
    </div>
  </body>
</html>
  )rawliteral";
