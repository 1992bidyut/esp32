const char success[] PROGMEM = R"rawliteral(

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

      .success-container {
        background-color: #28d9ed; /* Light green */
        border: 1px solid #c3e6cb; /* Darker green */
        color: #155724; /* Dark text color */
        padding: 15px;
        border-radius: 8px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        width: 300px;
        text-align: center;
      }

      .success-icon {
        font-size: 24px;
        margin-bottom: 10px;
        color: #28a745; /* Green color for the icon */
      }

      button {
        background-color: #28a745; /* Green */
        color: #fff;
        padding: 10px 15px;
        border: none;
        border-radius: 4px;
        cursor: pointer;
      }

      button:hover {
        background-color: #218838; /* Darker green */
      }
    </style>
  </head>
  <body>
    <div class="success-container">
      <span class="success-icon">&#10004;</span>
      <!-- Checkmark icon -->
      <p>Opreation successful.</p>
    </div>
  </body>
</html>


  )rawliteral";
