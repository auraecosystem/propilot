// an API supported only on Windows.
[SupportedOSPlatform("windows")]
public void WindowsOnlyApi() { }

// an API supported on Windows and Linux.
[SupportedOSPlatform("Windows")]
[SupportedOSPlatform("Linux")]
public void SupportedOnWindowsAndLinuxOnly() { }

// an API only supported on Windows 6.2 and later, not supported for all other.
// an API is removed/unsupported from version 10.0.19041.0.
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void ApiSupportedFromWindows8UnsupportedFromWindows10() { }

// an Assembly supported on Windows, the API added from version 10.0.19041.0.
[assembly: SupportedOSPlatform("Windows")]
[SupportedOSPlatform("windows10.0.19041.0")]
public void AssemblySupportedOnWindowsApiSupportedFromWindows10() { }

[SupportedOSPlatform("windows6.2")] // call site attributed Windows 6.2 or above.
public void Caller()
{
    WindowsOnlyApi(); // will not warn as call site is for Windows.

    // will not warn as call site is for Windows all versions.
    SupportedOnWindowsAndLinuxOnly();

    // will not warn for the [SupportedOSPlatform("windows6.2")] attribute, but warns for [UnsupportedOSPlatform("windows10.0.19041.0")]
    // This call site is reachable on: 'windows' 6.2 and later. 'ApiSupportedFromWindows8UnsupportedFromWindows10()' is unsupported on: 'windows' 10.0.19041.0 and later.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // The call site version is lower than the calling version, so warns:
    // This call site is reachable on: 'windows' 6.2 and later. 'AssemblySupportedOnWindowsApiSupportedFromWindows10()' is only supported on: 'windows' 10.0.19041.0 and later
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

[SupportedOSPlatform("windows10.0.22000")] // call site attributed with windows 10.0.22000 or above.
public void Caller2()
{
    // This call site is reachable on: 'windows' 10.0.22000 and later. 'ApiSupportedFromWindows8UnsupportedFromWindows10()' is unsupported on: 'windows' 10.0.19041.0 and later.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // will not warn as call site version higher than calling API.
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")] // call site supports Windows from version 6.2 to 10.0.19041.0.
public void Caller3()
{
    // will not warn as caller has exact same attributes.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // The call site reachable for the version not supported in the calling API, therefore warns:
    // This call site is reachable on: 'windows' from version 6.2 to 10.0.19041.0. 'AssemblySupportedOnWindowsApiSupportedFromWindows10()' is only supported on: 'windows' 10.0.19041.0 and later.
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

// an API not supported on Android but supported on all other.
[UnsupportedOSPlatform("android")]
public void DoesNotWorkOnAndroid() { }

// an API was unsupported on Windows until version 6.2.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
public void StartedWindowsSupportFromVersion8() { }

// an API was unsupported on Windows until version 6.2.
// Then the API is removed (unsupported) from version 10.0.19041.0.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void StartedWindowsSupportFrom8UnsupportedFrom10() { }

[UnsupportedOSPlatform("windows")] // Caller no support Windows for any version.
public void Caller4()
{
    // This call site is reachable on all platforms.'DoesNotWorkOnAndroid()' is unsupported on: 'android'
    DoesNotWorkOnAndroid();

    // will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFromVersion8();

    // same, will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFrom8UnsupportedFrom10();
}

[UnsupportedOSPlatform("windows")]
[UnsupportedOSPlatform("android")] // Caller not support Windows and Android for any version.
public void Caller4()
{
    DoesNotWorkOnAndroid(); // will not warn as call site not supports Android.

    // will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFromVersion8();

    // same, will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFrom8UnsupportedFrom10();
}
// An API supported only on Windows all versions.
[SupportedOSPlatform("Windows")]
public void WindowsOnlyApi() { }

// an API supported on Windows and Linux.
[SupportedOSPlatform("Windows")]
[SupportedOSPlatform("Linux")]
public void SupportedOnWindowsAndLinuxOnly() { }

// an API only supported on Windows 6.2 and later, not supported for all other.
// an API is removed/unsupported from version 10.0.19041.0.
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void ApiSupportedFromWindows8UnsupportedFromWindows10() { }

// an Assembly supported on Windows, the API added from version 10.0.19041.0.
[assembly: SupportedOSPlatform("Windows")]
[SupportedOSPlatform("windows10.0.19041.0")]
public void AssemblySupportedOnWindowsApiSupportedFromWindows10() { }

public void Caller()
{
    WindowsOnlyApi(); // warns: This call site is reachable on all platforms. 'WindowsOnlyApi()' is only supported on: 'windows'

    // This call site is reachable on all platforms. 'SupportedOnWindowsAndLinuxOnly()' is only supported on: 'Windows', 'Linux'
    SupportedOnWindowsAndLinuxOnly();

    // This call site is reachable on all platforms. 'ApiSupportedFromWindows8UnsupportedFromWindows10()' is only supported on: 'windows' from version 6.2 to 10.0.19041.0
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // for same platform analyzer only warn for the latest version.
    // This call site is reachable on all platforms. 'AssemblySupportedOnWindowsApiSupportedFromWindows10()' is only supported on: 'windows' 10.0.19041.0 and later
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

// an API not supported on android but supported on all other.
[UnsupportedOSPlatform("android")]
public void DoesNotWorkOnAndroid() { }

// an API was unsupported on Windows until version 6.2.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
public void StartedWindowsSupportFromVersion8() { }

// an API was unsupported on Windows until version 6.2.
// Then the API is removed (unsupported) from version 10.0.19041.0.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void StartedWindowsSupportFrom8UnsupportedFrom10() { }

public void Caller2()
{
    DoesNotWorkOnAndroid(); // This call site is reachable on all platforms.'DoesNotWorkOnAndroid()' is unsupported on: 'android'

    // This call site is reachable on all platforms. 'StartedWindowsSupportFromVersion8()' is unsupported on: 'windows' 6.2 and before.
    StartedWindowsSupportFromVersion8();

    // This call site is reachable on all platforms. 'StartedWindowsSupportFrom8UnsupportedFrom10()' is supported on: 'windows' from version 6.2 to 10.0.19041.0
    StartedWindowsSupportFrom8UnsupportedFrom10();
}
// an API supported only on Windows.
[SupportedOSPlatform("windows")]
public void WindowsOnlyApi() { }

// an API supported on Windows and Linux.
[SupportedOSPlatform("Windows")]
[SupportedOSPlatform("Linux")]
public void SupportedOnWindowsAndLinuxOnly() { }

// an API only supported on Windows 6.2 and later, not supported for all other.
// an API is removed/unsupported from version 10.0.19041.0.
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void ApiSupportedFromWindows8UnsupportedFromWindows10() { }

// an Assembly supported on Windows, the API added from version 10.0.19041.0.
[assembly: SupportedOSPlatform("Windows")]
[SupportedOSPlatform("windows10.0.19041.0")]
public void AssemblySupportedOnWindowsApiSupportedFromWindows10() { }

[SupportedOSPlatform("windows6.2")] // call site attributed Windows 6.2 or above.
public void Caller()
{
    WindowsOnlyApi(); // will not warn as call site is for Windows.

    // will not warn as call site is for Windows all versions.
    SupportedOnWindowsAndLinuxOnly();

    // will not warn for the [SupportedOSPlatform("windows6.2")] attribute, but warns for [UnsupportedOSPlatform("windows10.0.19041.0")]
    // This call site is reachable on: 'windows' 6.2 and later. 'ApiSupportedFromWindows8UnsupportedFromWindows10()' is unsupported on: 'windows' 10.0.19041.0 and later.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // The call site version is lower than the calling version, so warns:
    // This call site is reachable on: 'windows' 6.2 and later. 'AssemblySupportedOnWindowsApiSupportedFromWindows10()' is only supported on: 'windows' 10.0.19041.0 and later
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

[SupportedOSPlatform("windows10.0.22000")] // call site attributed with windows 10.0.22000 or above.
public void Caller2()
{
    // This call site is reachable on: 'windows' 10.0.22000 and later. 'ApiSupportedFromWindows8UnsupportedFromWindows10()' is unsupported on: 'windows' 10.0.19041.0 and later.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // will not warn as call site version higher than calling API.
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")] // call site supports Windows from version 6.2 to 10.0.19041.0.
public void Caller3()
{
    // will not warn as caller has exact same attributes.
    ApiSupportedFromWindows8UnsupportedFromWindows10();

    // The call site reachable for the version not supported in the calling API, therefore warns:
    // This call site is reachable on: 'windows' from version 6.2 to 10.0.19041.0. 'AssemblySupportedOnWindowsApiSupportedFromWindows10()' is only supported on: 'windows' 10.0.19041.0 and later.
    AssemblySupportedOnWindowsApiSupportedFromWindows10();
}

// an API not supported on Android but supported on all other.
[UnsupportedOSPlatform("android")]
public void DoesNotWorkOnAndroid() { }

// an API was unsupported on Windows until version 6.2.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
public void StartedWindowsSupportFromVersion8() { }

// an API was unsupported on Windows until version 6.2.
// Then the API is removed (unsupported) from version 10.0.19041.0.
// The API is considered supported everywhere else without constraints.
[UnsupportedOSPlatform("windows")]
[SupportedOSPlatform("windows6.2")]
[UnsupportedOSPlatform("windows10.0.19041.0")]
public void StartedWindowsSupportFrom8UnsupportedFrom10() { }

[UnsupportedOSPlatform("windows")] // Caller no support Windows for any version.
public void Caller4()
{
    // This call site is reachable on all platforms.'DoesNotWorkOnAndroid()' is unsupported on: 'android'
    DoesNotWorkOnAndroid();

    // will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFromVersion8();

    // same, will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFrom8UnsupportedFrom10();
}

[UnsupportedOSPlatform("windows")]
[UnsupportedOSPlatform("android")] // Caller not support Windows and Android for any version.
public void Caller4()
{
    DoesNotWorkOnAndroid(); // will not warn as call site not supports Android.

    // will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFromVersion8();

    // same, will not warns as the call site not support Windows at all, but supports all other.
    StartedWindowsSupportFrom8UnsupportedFrom10();
}
