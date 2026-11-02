// compute_shader.hlsl
RWStructuredBuffer<uint> results : register(u0);
StructuredBuffer<uint> sharedArray : register(t0);

[numthreads(256, 1, 1)]
void CSMain(uint3 DTid : SV_DispatchThreadID)
{
    uint instanceNumber = DTid.x;
    uint resultIndex = instanceNumber * 128;

    uint findCount = 0;
    for (uint i = 0; i < sharedArray.Length && findCount < 128; ++i)
    {
        uint divisor = sharedArray[i];
        if (divisor != 0 && instanceNumber % divisor == 0)
        {
            results[resultIndex + findCount] = divisor;
            findCount++;
        }
    }

    // Zero out unused
    for (uint j = findCount; j < 128; ++j)
        results[resultIndex + j] = 0;
}
