/* This is themain function that is called when the form is about to be submitted */
function formValidation(form)
{
    var state = true;
    var totalErrorCheck = 0;

    totalErrorCheck = validatePassword(form.password);
    if (totalErrorCheck > 0)
    {
        state = false;
    }

    if (state)
    {
        totalErrorCheck = validatePasswordRetype(form.passwordRetype, form.password);
        if (totalErrorCheck > 0)
        {
            state = false;
        }
    }

    if (state)
    { 
        totalErrorCheck = validateFirstName(form.firstName);
        if (totalErrorCheck > 0)
        {
            state = false;
        }
       
    }


    if (state)
    {
        totalErrorCheck = validateLastName(form.lastName);
        if (totalErrorCheck > 0)
        {
            state = false;
        }
        
    }

    if (state)
    {
        totalErrorCheck = validatePhoneNo(form.phoneNo);
        if (totalErrorCheck > 0)
        {
            state = false;
        }
        
    }

    if (state)
    {
        totalErrorCheck = validateEducation(form.educationalStatus);
        if (totalErrorCheck > 0)
        {
            state = false;
        }
        
    }

    return state;
}

/* This function validates the password field */
function validatePassword(elem)
{
    var message = document.querySelector("#passwordErrField");
    message.innerHTML = "";
    var lowerCase = "abcdefghijklmnopqrstuvwxyz";
    var err1 = 0;
    var upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var err2 = 0;
    var trimmedValue = elem.value.trim();
    var valueLength = trimmedValue.length;
    var status = true;
    var errorCounter = 0;
    for (var i = 0; i < valueLength; i++)
    {
        if (lowerCase.indexOf(trimmedValue.substr(i,1)) >= 0)
        {
            err1++;
        }
        if (upperCase.indexOf(trimmedValue.substr(i,1)) >= 0)
        {
            err2++;
        }
    }
    if (err1 < 1 || err2 < 1)
    {
        status = false;
        errorCounter++;
        elem.focus();
        message.innerHTML = "<mark>Password must contain both upper and lower case characters</mark>";
    }
        if (status)
        {
             var pattern1 = /^[0-9]{1,}$/;
             var err = 0;
            for (var i = 0; i < valueLength; i++) 
            {
               var test1 = pattern1.test(trimmedValue.substr(i,1));
               if (test1)
               {
                    err++;
               }
            }  
           
            if (err < 1)
            {
                status = false;
                errorCounter++;
                elem.focus();
                message.innerHTML = "<mark>Password must contain at least one number (0-9)</mark>";
            }
            
        }
        if (status)
        {
            if (valueLength < 8)
            {
                status = false;
                errorCounter++;
                elem.focus();
                message.innerHTML = "<mark>Password must be at least 8 characters long</mark>";
            }
        }

    return errorCounter;
}

/* This function validates the retyped password field */
function validatePasswordRetype(elem, elem1)
{
    var message = document.querySelector("#passwordRetypeErrField");
    message.innerHTML = "";
    var lowerCase = "abcdefghijklmnopqrstuvwxyz";
    var err1 = 0;
    var upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var err2 = 0;
    var trimmedValue = elem.value.trim();
    var valueLength = trimmedValue.length;
    var status = true;
    var errorCounter = 0;
    for (var i = 0; i < valueLength; i++)
    {
        if (lowerCase.indexOf(trimmedValue.substr(i,1)) >= 0)
        {
            err1++;
        }
        if (upperCase.indexOf(trimmedValue.substr(i,1)) >= 0)
        {
            err2++;
        }
    }
    if (err1 < 1 || err2 < 1)
    {
        status = false;
        errorCounter++;
        elem.focus();
        message.innerHTML = "<mark>Password must contain both upper and lower case characters</mark>";
    }
        if (status)
        {
             var pattern1 = /^[0-9]{1,}$/;
             var err = 0;
            for (var i = 0; i < valueLength; i++) 
            {
               var test1 = pattern1.test(trimmedValue.substr(i,1));
               if (test1)
               {
                    err++;
               }
            }  
           
            if (err < 1)
            {
                status = false;
                errorCounter++;
                elem.focus();
                message.innerHTML = "<mark>Password must contain at least one number (0-9)</mark>";
            }
            
        }
        if (status)
        {
            if (valueLength < 8)
            {
                status = false;
                errorCounter++;
                elem.focus();
                message.innerHTML = "<mark>Password must be at least 8 characters long</mark>";
            }
        }

        if (status)
        {
            var err = 0;
            var passwordValue = elem1.value.trim();
            for (var i = 0; i < valueLength; i++)
            {
                if (passwordValue.charAt(i) !== trimmedValue.charAt(i))
                {
                    err++;
                }
            }
            if (err > 0)
            {
                status = false;
                errorCounter++;
                elem.focus();
                message.innerHTML = "<mark>The password is not the same</mark>";
            }
        }

    return errorCounter;
}

/* This function validates the first name field */
function validateFirstName(elem)
{
    var ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'-";
    var ref2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    var errorChecker = 0;
    var status = true;
    var message = document.querySelector("#firstNameErrField");
    message.innerHTML = " ";
    var trimmedValue = elem.value.trim();
    var valueLength = elem.value.trim().length;
    if (valueLength < 1)
    {
        status = false;
        errorChecker++;
        elem.focus();
        message.innerHTML = "<mark>Please enter your first name</mark>";
    }
    
    if (status)
    { 
         var errorCounter = 0;
        for (var i = 0; i < valueLength; i++)
        {
            if (ref.indexOf(trimmedValue.substr(i, 1)) < 0)
            {
                errorCounter++;
            }
        }
        if (errorCounter > 0)
        {
            status = false;
            errorChecker++;
            elem.focus();
            message.innerHTML = "<mark>Only alphabetic characters (a-z), (A-Z), hyphen (-) and apostrophe (') are allowed</mark>";
        }
        
    }

    if (status)
    {
        var alphacharacter = 0;
        for (var i = 0; i < valueLength; i++)
        {
            if (ref2.indexOf(trimmedValue.substr(i, 1)) >= 0)
            {
                alphacharacter++;
            }
            if (alphacharacter < 1)
            {
                status = false;
                errorChecker++;
                elem.focus();
                message.innerHTML = "<mark>Please enter at least 1 alphabetic character (a-z) or (A-Z)</mark>";
            }
        }
    }

    return errorChecker;
}

/* This funtion validates the last name field */
function validateLastName(elem)
{
    var ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'-";
    var ref2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    var errorChecker = 0;
    var status = true;
    var message = document.querySelector("#lastNameErrField");
    message.innerHTML = " ";
    var trimmedValue = elem.value.trim();
    var valueLength = elem.value.trim().length;
    if (valueLength < 1)
    {
        status = false;
        errorChecker++;
        elem.focus();
        message.innerHTML = "<mark>Please enter your last name</mark>";
    }
    
    if (status)
    { 
         var errorCounter = 0;
        for (var i = 0; i < valueLength; i++)
        {
            if (ref.indexOf(trimmedValue.substr(i, 1)) < 0)
            {
                errorCounter++;
            }
        }
        if (errorCounter > 0)
        {
            status = false;
            errorChecker++;
            elem.focus();
            message.innerHTML = "<mark>Only alphabetic characters (a-z), (A-Z), hyphen (-) and apostrophe (') are allowed</mark>";
        }
        
    }

    if (status)
    {
        var alphacharacter = 0;
        for (var i = 0; i < valueLength; i++)
        {
            if (ref2.indexOf(trimmedValue.substr(i, 1)) >= 0)
            {
                alphacharacter++;
            }
            if (alphacharacter < 1)
            {
                status = false;
                errorChecker++;
                elem.focus();
                message.innerHTML = "<mark>Please enter at least 1 alphabetic character (a-z) or (A-Z)</mark>";
            }
        }
    }

    return errorChecker;
}

/* This funtion validates the phone number field */
function validatePhoneNo(elem)
{
    var message = document.querySelector("#phoneNoErrField");
    message.innerHTML = "";
    var errorChecker = 0;
    var status = true;
    var value = elem.value.trim();
    var valueLength = value.length;
    var pattern = /^([0-9]{3}[-]){2}[0-9]{4}$/;
    if (valueLength === 0)
    {
        errorChecker++;
        elem.focus();
        message.innerHTML = "<mark>Please enter your phone number</mark>";
        status = false;
    }
    if (status)
    {
        var state = pattern.test(value);
        if (!state)
        {
            errorChecker++;
            elem.focus();
            message.innerHTML = "<mark>Please enter your phone number in this format: '999-999-9999'</mark>";
            status = false;
        }
    }
    if (status)
    {
        var areaCodeTest = /^[0]{3}$/;
        var areaCode = value.substr(0,3);
        var state = areaCodeTest.test(areaCode);
        if (state)
        {
            errorChecker++;
            status = false;
            elem.focus();
            message.innerHTML = "<mark>The area code (first 3 numbers) can't be all zeros (0)!</mark>";
        }
    if (status)
    {
            var phoneNoTest = /^[-][0]{3}[-][0]{4}$/;
            var phoneNo = value.substr(3,9);
            var state = phoneNoTest.test(phoneNo);
            if (state)
            {
            errorChecker++;
            status = false;
            elem.focus();
            message.innerHTML = "<mark>The actual phone number can't be all zeros (0)!</mark>";
            }
        }
    }
    return errorChecker;
}

/* This funtion validates the education status field */
function validateEducation(elem)
{
    var errorChecker = 0;
    var status = 0;
    var message = document.querySelector("#educationErrField");
    message.innerHTML = "";
    for (var i = 0; i < elem.length; i++)
    {
        if (elem[i].checked == true)
        {
            errorChecker++;
        }
    }
    if (errorChecker < 1)
    {
        status = 1;
        message.innerHTML = "<mark>Please select your educational status</mark>";
    }
    return status;
}